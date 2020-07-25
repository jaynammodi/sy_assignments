# writer for assignments v1
import sys, os
from reportlab.pdfgen.canvas import Canvas
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.platypus import Paragraph, Image, SimpleDocTemplate, Spacer
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.units import cm, inch
from reportlab.lib.enums import TA_JUSTIFY
import textract
from datetime import date

curdate = date.today().strftime("%b %d, %Y")

infile = sys.argv[1]

outfile = "output/{}".format("pdf_"+ infile[:-5] + ".pdf")

global mystyle

def firstGraphics(canvas, doc):
	print(canvas)
	defaultGraphics(canvas, doc)
	canvas.setFont(mystyle.fontName, mystyle.fontSize)
	title = infile[:-5]
	canvas.drawCentredString(A4[0]/2, A4[1] - 2.0 * cm, title)

def defaultGraphics(canvas, doc):
	canvas.drawImage("A4_Page.jpg", 0, 0, width = A4[0], height = A4[1])

dat = textract.process(infile).decode('utf-8')

pdfmetrics.registerFont(TTFont('Daniel', 'Daniel.ttf'))
pdfmetrics.registerFont(TTFont('Khand', 'khand.ttf'))

doc = SimpleDocTemplate(outfile, pagesize = A4)

doc.topMargin = 2.5 * cm
doc.leftMargin = 0.5 * cm
doc.rightMargin = 0.5 * cm
doc.bottomMargin = 1.0 * cm


styles = getSampleStyleSheet()
mystyle = styles['Normal']

mystyle.fontName = "Khand"
mystyle.fontSize = 0.8 * cm
#mystyle.leading = float(sys.argv[2]) * cm
mystyle.leading = 0.826 * cm
mystyle.alignment = TA_JUSTIFY
mystyle.bulletIndent = 0.9 * cm
mystyle.leftIndent = 1.8 * cm
mystyle.textColor = "#182084"
#mystyle.autoLeading = "max"

data = [Paragraph("Jaynam Modi.  PG-43.  G3.  {}".format(curdate), mystyle)]

for x in dat.split("\n"):
	x = x.strip()
	if x != "":
		if "<buljrkrlet>" in x:
			x = x.strip("<bullet>")
			mytext = Paragraph(x, mystyle, bulletText = "•")
		else:
			mytext = Paragraph(x, mystyle)
		data.append(mytext)
	else:
		data.append(Spacer(0, 0.826 * cm))

doc.build(data, onFirstPage = firstGraphics, onLaterPages = defaultGraphics)

os.system("termux-open {}".format(outfile))