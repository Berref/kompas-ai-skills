# ksSetObjParam - Установить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) |  Scroll [ [ [ ](ksdocumenttxt_rasterformatparam.html "К следующему разделу")](ksdocumenttxt_methods.html "На уровень выше")](ksdocumenttxt_kssavedocumentex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumenttxt.html)

Аналог данного метода при использовании API экспортных функций - [SetObjParam](setobjparam.html).

Синтаксис Automation:

long ksSetObjParam (long reference, LPDISPATCH param, long paramType);

Входные параметры:

reference | \- указатель на объект,  
---|---  
paramType | \- тип параметров объекта,  
param | \- указатель на интерфейс параметров.  
  
[Типы объектов и интерфейсы...](objtypes.html)

Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Параметр paramType может принимать значения ALLPARAM, SHEET_ALLPARAM, DOCUMENT_STATE.

2\. Типом объекта может быть TXT_DOCUMENT_OBJ.

3\. Перед применением метода указатель param должен быть задан, например, с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html).

Подразделы:

(отсутствуют)
