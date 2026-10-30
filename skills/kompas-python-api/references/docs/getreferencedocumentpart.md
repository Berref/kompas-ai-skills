# GetReferenceDocumentPart - Получить указатель на основную надпись или технические требования, или неуказанную шероховатость, или текущий вид, или спецификацию на листе

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](getreferencedocumentpartex.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](getstampcolumntext.html "К предыдущему разделу")  
---|---  
  
[Пример...](getreferencedocumentpart_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetReferenceDocumentPart](ksdocument2d_ksgetreferencedocumentpart.html).

Синтаксис:

reference GetReferenceDocumentPart (unsigned char t);

Входной параметр:

t | \- [Тип объекта оформления чертежа](sheetobjtypes.html).  
---|---  
  
Возвращаемое значение:

указатель на объект выбранного типа | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод предназначен для использования в листе чертежа.

Подразделы:

(отсутствуют)
