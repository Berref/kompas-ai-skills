# GetTextLength - Получить длину текста

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Простановка текстовых надписей ](cm1738402.html) > [Функции работы с текстовыми надписями и таблицами ](text_labels_fncts_common.html) |  Scroll [ [ [ ](gettextlengthw.html "К следующему разделу")](text_labels_fncts_common.html "На уровень выше")](text_labels_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](gettextlength_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetTextLength](ksdocument2d_ksgettextlength.html).

Синтаксис:

double GetTextLength (char * text, unsigned short style);

Входные параметры:

style | \- стиль текста.  
---|---  
  
[Системные стили текстов...](tstyles.html)

Входные параметры:

text | \- указатель на строку текста.  
---|---  
  
Возвращаемое значение:

| вычисленное значение длины текста (в миллиметрах).  
---|---  
  
Примечание:

1\. Функция может принимать строку в синтаксисе версии КОМПАС 4 (спецзнаки, дроби, отклонения).

2\. При использовании Unicode следует использовать функцию [GetTextLengthW](gettextlengthw.html).

Подразделы:

(отсутствуют)
