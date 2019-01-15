# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class TianzhanbeiItem(scrapy.Item):
    # define the fields for your item here like:

    name=scrapy.Field()
    origin=scrapy.Field()
    category=scrapy.Field()
class theseusItem(scrapy.Item):
    paper=scrapy.Field()
    url=scrapy.Field()
    cate=scrapy.Field()
    author=scrapy.Field()
    subject=scrapy.Field()
    keyword=scrapy.Field()
    year=scrapy.Field()
    institution=scrapy.Field()
    degree=scrapy.Field()
    
    
    
