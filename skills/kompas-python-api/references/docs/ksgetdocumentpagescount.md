# ksGetDocumentPagesCount - Получить количество листов документа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](ksrebuilddocument.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](ksgetzonaw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetDocumentPagesCount](ksdocument2d_ksgetdocumentpagescount.html).

Синтаксис:

int ksGetDocumentPagesCount (reference pDoc);

Входные параметры:

pDoc | \- указатель на документ.  
---|---  
  
Возвращаемое значение:

| \- количество листов документа.  
---|---  
  
Примечание:

Если pDoc = 0, метод вызывается для текущего документа.
