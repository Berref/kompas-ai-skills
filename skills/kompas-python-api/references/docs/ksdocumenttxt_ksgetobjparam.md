# ksGetObjParam - Получить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) |  Scroll [ [ [ ](ksdocumenttxt_ksopendocument.html "К следующему разделу")](ksdocumenttxt_methods.html "На уровень выше")](ksdocumenttxt_ksgetdocumentpagescount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumenttxt.html)

Аналог данного метода при использовании API экспортных функций - [GetObjParam](getobjparam.html).

Синтаксис Automation:

long ksGetObjParam (long reference, LPDISPATCH param, long paramType);

Входные параметры:

reference | \- указатель на объект,  
---|---  
paramType | \- тип параметров объекта.  
  
Выходные параметры:

param | \- указатель на интерфейс параметров.  
---|---  
  
[Типы объектов и интерфейсы...](objtypes.html)

Возвращаемое значение:

тип объекта | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Параметр paramType может принимать значения ALLPARAM, SHEET_ALLPARAM, DOCUMENT_STATE.

2\. Возвращаемым значением может быть TXT_DOCUMENT_OBJ.

3\. Перед применением метода указатель param должен быть задан, например, с помощью метода[ KompasObject::GetParamStruct](kompasobject_getparamstruct.html).

4\. Вызов метода с нулевыми значениями параметров param и parType позволяет получить тип объекта по его reference.

Подразделы:

(отсутствуют)
