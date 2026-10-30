# GetTextLengthW - Получить длину текста (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Простановка текстовых надписей ](cm1738402.html) > [Функции работы с текстовыми надписями и таблицами ](text_labels_fncts_common.html) |  Scroll [ [ [ ](gettextlengthfromreference.html "К следующему разделу")](text_labels_fncts_common.html "На уровень выше")](gettextlength.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetTextLength](ksdocument2d_ksgettextlength.html).

Синтаксис:

double LIB_FUNC GetTextLengthW (LPWSTR text, unsigned short style);

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

2\. При использовании ANSI следует использовать функцию [GetTextLength](gettextlength.html).

Подразделы:

(отсутствуют)
