# ksSetObjParam - Установить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) |  Scroll [ [ [ ](ksspcdocument_kssetspcsheetsb.html "К следующему разделу")](ck1881939.html "На уровень выше")](ksspcdocument_kssavetodxf.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocument.html)

Аналог данного метода при использовании API экспортных функций - [SetObjParam](setobjparam.html).

Синтаксис Automation:

long ksSetObjParam (long reference,

LPDISPATCH param,

long paramType);

Входные параметры:

reference | \- указатель на объект,  
---|---  
paramType | \- тип параметров,  
param | \- указатель на интерфейс параметров [ksUserParam](ksuserparam.html).  
  
[Типы параметров объектов...](paramtypes.html)

[Типы объектов и интерфейсы...](objtypes.html)

Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Параметр paramType может принимать значения ALLPARAM, SHEET_ALLPARAM, DOCUMENT_STATE, SPC_TUNING_PARAM.

2\. Типом объекта может быть SPC_OBJ или SPC_DOCUMENT_OBJ.

Подразделы:

(отсутствуют)
