# -*- coding: utf-8 -*-
# @Time    : 2018/10/27 18:27
# @Author  : 201619630303_杜天启
# @FileName: item.py
# @Software: PyCharm

class item:
	def __init__(self,value,weight):
		self.value=value
		self.weight=weight
		self.benefit_per_wieght=value/weight
		self.choosed=False
		self.bag=None