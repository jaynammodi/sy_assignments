# writer for assignments v1
import sys, os, re
from reportlab.pdfgen.canvas import Canvas
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.platypus import Paragraph, Image, SimpleDocTemplate, Spacer, Table, TableStyle, Indenter
from reportlab.platypus.flowables import DocPara
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.units import cm, inch
from reportlab.lib.enums import TA_JUSTIFY
import textract
from pathlib import Path
from xml.sax.saxutils import escape
from datetime import date
import docx


curdate = date.today().strftime("%b %d, %Y")

infile = sys.argv[1]

outfile = "output/{}".format("pdf_"+ Path(infile).stem + ".pdf")

global mystyle
global blackstyle

def processdoc(infile):
	
	datalist = []
	
	data = textract.process(infile).decode('utf-8')
	
	if ".docx" in infile:
		table_data = docx.Document(infile)
		table_list = []
		for table in table_data.tables:
			txt_form = ""
			new_table = []
			for row in table.rows:
				temp = []
				for cell in row.cells:
					temp.append(cell.text)
					txt_form = txt_form + "{}\n\n".format(cell.text)
				new_table.append(temp)
			table_list.append(new_table)
			data = data.replace(txt_form, "!~table_key({})~!".format(len(table_list)-1))
	
	data = data.replace("•", "<bullet fontSize=20>•</bullet>")
	data = data.replace(".>", "<bullet fontSize=20>></bullet>")
	data = data.replace("()", "( )")
	p = re.compile("!\\~s(\d{1,2})")
	data = p.sub("<bullet fontSize=12><seq id=\\1/>.</bullet>", data)
	#data = re.sub("```(\w+)```", "<paragraph fontName=Daniel>\\1</paragraph>", data)
	lefti = Indenter(left = 1.8 * cm)
	mlefti = Indenter(left = -1.8 * cm)
	data = data.replace("’", "'")
	data = data.replace("”", '"')
	data = data.replace("“", '"')
	if "--keepspace" not in sys.argv:
		data = re.sub(r'\n{2,10}', "\n\n", data)
		
	for x in data.split("\n"):
		matches = re.findall('!\\~table_key\\((.*)\\)\\~!', x)
		if matches != []:
			datalist.append(table_list[int(matches[0])])
		elif "!~tab" in x:
			x = x.replace("!~tab", "")
			datalist.append(lefti)
	#		datalist.append(x)
		elif "tab~!" in x:
			x = x.replace("tab~!", "")
			datalist.append(mlefti)
			#datalist.append(x)
		elif "!~space~!" in x:
			datalist.append(Spacer(0, 5.782 * cm))
		else:
			try:
				if x[-1] == "{":
					datalist.append(x)
					datalist.append(lefti)
				elif "}" in x:
					datalist.append(mlefti)
					datalist.append(x)
				else:
					datalist.append(x)
			except:
				datalist.append(x)
				pass
		
		
	return datalist

def firstGraphics(canvas, doc):
	print(canvas)
	defaultGraphics(canvas, doc)
	canvas.setFont(mystyle.fontName, mystyle.fontSize)
	#canvas.setFillColor(mystyle.textColor)
	title = Path(infile).stem
	canvas.drawCentredString(A4[0]/2, A4[1] - 2.0 * cm, title)

def defaultGraphics(canvas, doc):
	canvas.drawImage("A4_Page.jpg", 0, 0, width = A4[0], height = A4[1])
	canvas.setFont(mystyle.fontName, 0.5 * cm)
	canvas.setFillColor(blackstyle.textColor)
	canvas.drawCentredString(A4[0] - 2.7 * cm, A4[1] - 1.25 * cm, str(canvas.getPageNumber()))


dat = processdoc(infile)

pdfmetrics.registerFont(TTFont('Daniel', 'Daniel.ttf'))
pdfmetrics.registerFont(TTFont('Khand', 'khand.ttf'))

doc = SimpleDocTemplate(outfile, pagesize = A4)

doc.topMargin = 2.6 * cm
doc.leftMargin = 0.5 * cm
doc.rightMargin = 0.5 * cm
doc.bottomMargin = 1.0 * cm

styles = getSampleStyleSheet()
mystyle = styles['Normal']

mystyle.fontName = "Khand"
mystyle.fontSize = 0.8 * cm
mystyle.leading = 0.826 * cm
mystyle.alignment = TA_JUSTIFY
mystyle.bulletIndent = 0.3 * cm
mystyle.bulletFontName = "Daniel"
mystyle.bulletFontSize = 0.8 * cm
mystyle.leftIndent = 1.8 * cm
mystyle.textColor = "#182084"
#mystyle.autoLeading = "max"


blackstyle = getSampleStyleSheet()['Normal']
blackstyle.fontName = mystyle.fontName
blackstyle.fontSize = mystyle.fontSize
blackstyle.leading = mystyle.leading
blackstyle.alignment = mystyle.alignment
blackstyle.leftIndent = mystyle.leftIndent
blackstyle.textColor = "#000000"


tabstyle = TableStyle([
	("INNERGRID", (0,0), (-1,-1), 0.6, "#6F6D74"),
	("BOX", (0,0), (-1,-1), 0.6, "#6F6D74"),
	("FONT", (0,0), (-1,-1), mystyle.fontName),
	("TEXTCOLOR", (0,0), (-1,-1), "#6F6D74"),
	("FONTSIZE", (0,0), (-1,-1), 0.5 * cm),
	("ALIGNMENT", (0,0), (-1,-1), "CENTRE"),
	("VALIGN", (0,0), (-1,-1), "MIDDLE")
	])

data = []

data = [Paragraph("Jaynam Modi.  PG-43.  G3.  {}".format(curdate), blackstyle), Spacer(0, 0.826 * cm), Spacer(0, 0.826 * cm)]

for x in dat:
	if "--escape" in sys.argv:
		x = escape(x)
	try:
		x = x.strip(" ")
		if x != "":
			mytext = Paragraph(x, style=mystyle)
			data.append(mytext)
			#print (mytext)
			#data.append(Spacer(0, 0.826 * cm))
		else:
			data.append(Spacer(0, 0.826 * cm))
	except AttributeError as e:
		print(e.args)
		if "Indenter" in e.args[0]:
			data.append(x)
		elif "Spacer" in e.args[0]:
			data.append(x)
		else:
			mytable = Table(x, (A4[0] - 3 * cm)/len(x[0]), 0.826 * cm, style=tabstyle)
			data.append(Indenter(left = mystyle.leftIndent))
			data.append(mytable)
			data.append(Indenter(left = -mystyle.leftIndent))

doc.build(data, onFirstPage = firstGraphics, onLaterPages = defaultGraphics)

print(outfile)
os.system("termux-open {}".format(re.escape(outfile)))