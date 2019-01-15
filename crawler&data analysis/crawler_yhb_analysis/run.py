# -*- coding: utf-8 -*-
# @Time    : 12/7/2018 1:50 PM
# @Author  : 201619630303_杜天启
# @FileName: run.py
# @Software: PyCharm
from scrapy import cmdline


cmdline.execute("scrapy crawl my_spider".split())