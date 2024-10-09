# from urllib.request import urlopen
# from bs4 import BeautifulSoup
# html = urlopen("https://pythonscraping.com/")
# bsObj=BeautifulSoup(html.read())
# print(bsObj.h1)

from urllib.request import urlopen
html = urlopen("https://pythonscraping.com/")
print(html.read())

