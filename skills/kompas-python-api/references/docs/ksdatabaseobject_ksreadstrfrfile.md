# ksReadStrFrFile - Считать строку из текстового файла запросов

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksrelation.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksreadrecord.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [ReadStrFromTextFile](readstrfromtextfile.html).

Синтаксис Automation:

BSTR ksReadStrFrFile (long f,

long* res,

long numb);

Входные параметры:

f | \- указатель на текстовый файл,  
---|---  
numb | \- номер строки.  
  
Выходной параметр:

res | \- результат работы метода: 1 - в случае успешного завершения, 0 - в случае неудачи.  
---|---  
  
Возвращаемое значение:

| \- строка обращения к базе данных.  
---|---  
  
Примечание:

Строка обращения к базе данных начинается с номера, далее после двоеточия идет текст обращения, например:

3:select d,f from Table1 where d=10 and f>d

Подразделы:

(отсутствуют)
