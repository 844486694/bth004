# -*- coding: utf-8 -*-
# @Time    : 12/12/2018 7:33 PM
# @Author  : 201619630303_杜天启
# @FileName: proxy.py
# @Software: PyCharm
from tianzhanbei.middlewares.resource import PROXIES
import random


class RandomProxy(object):
    def process_request(self,request, spider):
        proxy = random.choice(PROXIES)
        request.meta['proxy'] = 'http://%s'% proxy