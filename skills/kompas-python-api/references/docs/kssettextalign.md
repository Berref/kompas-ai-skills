# ksSetTextAlign - Установить тип привязки текста

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Простановка текстовых надписей ](cm1738402.html) > [Функции работы с текстовыми надписями и таблицами ](text_labels_fncts_common.html) |  Scroll [ [ [ ](kssettextlinealign.html "К следующему разделу")](text_labels_fncts_common.html "На уровень выше")](kssettablecolumntext.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetsettextalign_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetTextAlign](ksdocument2d_kssettextalign.html).

Синтаксис:

int ksSetTextAlign (reference pText, unsigned int align);

Входные параметры:

pText | \- указатель на объект "текст",  
---|---  
align | \- тип привязки текста.  
  
[Типы привязки текста...](textalign.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
