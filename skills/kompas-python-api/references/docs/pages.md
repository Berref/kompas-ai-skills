# Pages.ру

[Инструкция по созданию справки HTML для приложений](help_for_applications.html) > [Локальная справка для приложений](local_help.html) > [База данных соответствия номеров команд и страниц справки](value_base.html) |  Scroll [ [ [ ](used_port.html "К следующему разделу")](value_base.html "На уровень выше")](value_base.html "К предыдущему разделу")  
---|---  
  
#!/usr/bin/python

# -*- coding: utf-8 -*-

from xml.dom import minidom

import argparse

import sqlite3 as sqlite

import sys

con = None

try:

# Получение аргументов командной строки

ap = argparse.ArgumentParser(description="Формирование базы данных по связи идентификатора и html страницы")

ap.add_argument("--outfile", "-o", type = str, default = 'pages.db', \

help = "Путь к результирующему файлу базы данных")

ap.add_argument("--hhfile", "-hh", type = str, default = 'KOMPAS.hh', \

help = "Путь к hh-файлу КОМПАС")

# ap.add_argument("--hhafile", "-hha", type = str, default = 'KOMPAS.hha', \

# help = "Путь к hha-файлу КОМПАС")

args = ap.parse_args()

print("HH-file: %s, HHA-file: %s, output file: %s\n" % (args.hhfile, args.hhafile, args.outfile))

# print("HH-file: %s, output file: %s\n" % (args.hhfile, args.outfile))

con = sqlite.connect(args.outfile)

cur = con.cursor()

print("==> Clean up (1 of 3)")

# Удалить таблицу с соответствием идентификаторов из hh c html страницами

cur.execute("DROP TABLE IF EXISTS Page")

cur.execute("CREATE TABLE Page(Id INTEGER, Page TEXT)")

print("<== Clean up\n")

# Составляем словарь псевдонимов идентификаторов

print("==> Reading aliases (2 of 3)")

err_count_hha = 0

aliases = { }

with open(args.hhafile) as hha:

for line in hha:

# Trim comments and whitespace

s = line.split(';')[0].strip()

# Split by "="

parts = s.split('=', 1)

# Обработать ошибочную ситуацию

if len(parts) == 1 and len(parts[0]) > 0:

print("[ERROR] Invalid line format!")

err_count_hha = err_count_hha + 1

# Запомнить псевдоним

if len(parts) == 2:

print("[OK] %s=%s" % (parts[0], parts[1]))

aliases[parts[0]] = parts[1]

print("<== Reading aliases (ERRORS: %d)\n" % err_count_hha)

print("==> Creating Page table (3 of 3)")

with open(args.hhfile) as hh:

for line in hh:

words = line.split()

if len(words) >= 3:

identifier = int(words[2])

name = words[1]

if name in aliases:

name = aliases[name]

else:

name = name + ".html"

cur.execute("INSERT INTO Page VALUES(%d, '%s')" % (identifier, name))

cur.execute("CREATE INDEX page_id_index ON Page(Id)")

con.commit()

# Общий отчёт о результате

print("===DONE (ERRORS: %d)===" % int(err_count_hha))

except sqlite.Error as e:

print("ERROR: %s!" % e.args[0])

sys.exit(1)

finally:

if con:

con.close()
