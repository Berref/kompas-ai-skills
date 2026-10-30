# GetReferenceDocumentPartEx - Получить указатель на объект оформления чертежа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](ksgetzona.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](getreferencedocumentpart.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetReferenceDocumentPartEx](ksdocument2d_ksgetreferencedocumentpartex.html).

Синтаксис:

reference GetReferenceDocumentPartEx (unsigned char t, int sheetNumb);

Входные параметры:

t | \- [Тип объекта оформления чертежа](sheetobjtypes.html).  
---|---  
sheetNumb | \- зависит от типа получаемого объекта оформления чертежа: для t=0 sheetNumb - номер листа, начиная с 1, для t=1 sheetNumb не используется, для t=2 sheetNumb не используется, для t=3 sheetNumb не используется, для t=4 sheetNumb - номер спецификации, начиная с 1; 0 - текущая спецификация, для t=5 sheetNumb не используется, для t=6 sheetNumb - номер листа, начиная с 1.  
  
Возвращаемое значение:

указатель на объект выбранного типа | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
