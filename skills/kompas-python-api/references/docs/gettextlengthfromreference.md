# GetTextLengthFromReference - Получить длину текста, заданного указателем

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Простановка текстовых надписей ](cm1738402.html) > [Функции работы с текстовыми надписями и таблицами ](text_labels_fncts_common.html) |  Scroll [ [ [ ](ksconverttexttocurve.html "К следующему разделу")](text_labels_fncts_common.html "На уровень выше")](gettextlengthw.html "К предыдущему разделу")  
---|---  
  
[Пример...](gettextlength_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetTextLengthFromReference](ksdocument2d_ksgettextlengthfromreference.html).

Синтаксис:

double GetTextLengthFromReference (reference pText);

Входной параметр:

pText | \- указатель на текст.  
---|---  
  
Возвращаемое значение:

| вычисленное значение длины текста (в миллиметрах).  
---|---  
  
Примечание:

Функция может принимать строку в синтаксисе версии КОМПАС 4 (спецзнаки, дроби, отклонения).

Подразделы:

(отсутствуют)
