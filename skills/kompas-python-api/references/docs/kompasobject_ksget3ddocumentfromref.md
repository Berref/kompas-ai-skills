# ksGet3dDocumentFromRef - Получить указатель на интерфейс ksDocument3D, соответствующий присланному указателю на документ

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksiskompascommandcheck.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetworkwindowcolor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGet3dDocumentFromReference](ksget3ddocumentfromreference.html).

Синтаксис Automation:

LPDISPATCH ksGet3dDocumentFromRef(long doc);

Входной параметр:

doc | \- указатель на документ.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс [ksDocument3D](ksdocument3d.html) | \- в случае удачного завершения,  
---|---  
NULL | \- если такого документа нет.  
  
Подразделы:

(отсутствуют)
