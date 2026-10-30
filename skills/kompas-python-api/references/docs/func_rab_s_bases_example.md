# Пример использования функций работы с базами данных

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//пример текстового файла 1.loa с тремя параметрами - шириной, высотой и типом линии прямоугольника

/*

10.0 100 1

15.0 80 2

20.0 120 1

*/

#ifndef __LIBTOOL_H

#include <libtool.h>

#endif

#ifndef __LIBDB_H

#include <libdb.h>

#endif

static void ReadFirstStatement(reference bd, reference r1, void *b) {

// вспомогательная функция чтения записей

char buf[40];

int i;

do { // считываем все записи выборки

i= ReadRecord(bd, r1, b);

if (i) {

sprintf(buf, "a=%4.1f b=%4.1f t= %d", b->a, b->b, b->t);

Message(buf);

}

} while(i);

Message("конец выборки");

} /* ReadFirstStatement */

void ExampleDB (void) {

int i;

char buf[40];

struct {

double a;

double b;

int t;

} b;

// создать блок заголовка базы данных

reference bd = CreateDB ("TXT_DB");

// связать с файлом базы данных 1.loa

ConnectDB(bd, "1.loa");

// задаем отношение из двух действительных и одного целого поля

reference r1 = Relation(bd);

RDouble ("a");

RDouble ("b");

RInt ("");

EndRelation();

// определяем запрос для считывания всех полей(колонок) записи

DoStatement(bd, r1, ""); // равносильно DoStatement(bd, r1, "1 2 3");

// cчитываем все записи

ReadFirstStatement(bd, r1, &b);

// выдать вторую запись

Condition(bd, r1, "Index1000 = 2");

ReadFirstStatement(bd, r1, &b);

// по условию выдать первую и третью запись(см. файл 1.loa)

Condition(bd, r1, "a=10 || b>100");

ReadFirstStatement(bd, r1, &b);

//задаем отношение для считывания только второго поля записи

reference r2 = Relation(bd);

RChar("b", 20, 0);

EndRelation();

// Освободить запрос базы данных

FreeStatement(bd, r1, «»);

DoStatement(bd, r2, "2");

do {

i= ReadRecord(bd, r2, buf);

if (i) {

Message(buf);

}

} while(i);

Message("конец выборки");

DisconnectDB(db);

// удаляем блок заголовка базы данных

DeleteDB(bd);

}; /* ExampleDB */
