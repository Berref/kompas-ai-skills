# ksGetTextLength - Получить длину текста в миллиметрах

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Текстовые надписи ](bt1731191.html) |  Scroll [ [ [ ](ksdocument2d_ksgettextlengthfromreference.html "К следующему разделу")](bt1731191.html "На уровень выше")](ksdocument2d_ksgettextalign.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetTextLength](gettextlength.html).

Синтаксис Automation:

double ksGetTextLength (BSTR text,

long style);

Входные параметры:

text | \- указатель на строку текста,  
---|---  
style | \- стиль текста.  
  
[Системные стили текстов...](tstyles.html)

Возвращаемое значение:

| \- вычисленное значение длины текста (в миллиметрах).  
---|---  
  
Примечание:

Функция может принимать строку в синтаксисе версии КОМПАС 4 (спецзнаки, дроби, отклонения).

Подразделы:

(отсутствуют)
