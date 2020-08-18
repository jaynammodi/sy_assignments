from pdf2image import convert_from_path
import img2pdf
import sys, os
from PIL import Image
import io

from random import randint, choice

image_pages = convert_from_path(sys.argv[1], fmt = "jpg", dpi = 300, thread_count = 8)

processed_pages = []

#for page in image_pages:

with image_pages[0] as page:
	
	print(page)
	new_image = page.copy()
	for x in range(page.size[0]):
		for y in range(page.size[1]):
			pix = page.getpixel((x,y))
			if pix[0] < 200:
				new_pix = (pix[0]-randint(25, 50)*choice([-1,1]),pix[1]-randint(25,50)*choice([-1,1]),pix[2]-randint(0,25)*choice([-1,1]))
				new_image.putpixel((x,y), new_pix)
	print(new_image)
	
	with io.BytesIO() as op:
		new_image.save(op, format="JPEG")
		processed_pages.append(op.getvalue())
#for x in range(len(processed_pages)):
#	processed_pages[x].save
	
	
	
with open("output.pdf", "wb") as f:
	f.write(img2pdf.convert(processed_pages))
	
os.system("termux-open {}".format("output.pdf"))