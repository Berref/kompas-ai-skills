# OpenTextFile, CloseTextFile, ReadStrFromTextFile- пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
////////////////////////////////////////////////////////////////////////

//пример текстового файла 1.loa

10.0 100 1

15.0 80 2

20.0 120 1

////////////////////////////////////////////////////////////////////////

//пример текстового файла запросов 11.txt привязанный к файлу 1.loa

1:TXT_DB

2:1.loa

3:1 2 3

4:a=%.1f

//////////////////////////////////////////////////////////////////////////

//пример текстового файла запросов 12.txt привязанный к БД ACCECC c именем

// test в ODBC.INI. ODBCSDK должен быть установлен на ПК

1:ODBC_DB

2:test

3:select a,b,t from table1

4:where a=%.1f

//////////////////////////////////////////////////////////////////////////

#ifndef __LIBTOOL_H

#include <libtool.h>

#endif

#ifndef __LIBDB_H

#include <libdb.h>

#endif

void DrawRect (void) {

char buf[40], s[128];

struct {

double a;

double b;

int t;

} r;

reference f = OpenTextFile("11.txt");

if (EditMacroMode()) //режим редактирования

GetMacroParam(&r, sizeof(r));

else { //cоздание нового макроэлемента

r.a = 20;

r.b = 10;

}

// считали тип БД - "TXT_DB"

if (!ReadStrFromTextFile(f,buf,1)) {Error("Ошибка"); return; }

reference bd = CreateDB (buf);

// считали имя БД - "1.loa"

if (!ReadStrFromTextFile(f,buf,2)) {Error("Ошибка"); return; }

ConnectDB(bd, buf);

//задаем отношение

reference r1 = Relation(bd);

RDouble ("a");

RDouble ("b");

RInt ("");

EndRelation();

//считывать все колонки "1 2 3"

if (!ReadStrFromTextFile(f,buf,3)) {Error("Ошибка"); return; }

DoStatement(bd, r1, buf);

ReadDouble("задайте ширину",r.a,0,100, &r.a);

//считать условие "a=%.1f"

if (!ReadStrFromTextFile(f,buf,4)) {Error("Ошибка"); return; }

sprintf (s, buf,r.a); // условие например a=10.0

Condition(bd, r1, s);

if (ReadRecord(bd, r1, &r)) {

reference m = Macro();

LineSeg(0, 0, r.a, 0, r.t);

LineSeg(r.a, 0, r.a, r.b, r.t);

LineSeg(r.a, r.b, 0, r.b, r.t);

LineSeg(0, r.b, 0, 0, r.t);

EndObj();

//записать параметры в макроэлемент

SetMacroParam( m, &r, sizeof(r), NULL, NULL, -1);

}

else

Error("прямоугольник с такими параметрами не найден в БД");

DeleteDB(bd);

CloseTextFile(f);

}; /* OpenTextFile */
