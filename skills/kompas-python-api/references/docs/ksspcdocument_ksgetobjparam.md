# ksGetObjParam - Получить параметры объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) |  Scroll [ [ [ ](ksspcdocument_ksgetspcdocumentpagescount.html "К следующему разделу")](ck1881939.html "На уровень выше")](ksspcdocument_ksexistobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocument.html)

Аналог данного метода при использовании API экспортных функций - [GetObjParam](getobjparam.html).

Синтаксис Automation:

long ksGetObjParam (long reference,

LPDISPATCH param,

long paramType);

Входные параметры:

reference | \- указатель на объект,  
---|---  
paramType | \- тип параметров,  
param | \- указатель на интерфейс параметров [ksUserParam](ksuserparam.html).  
  
[Типы параметров объектов...](paramtypes.html)

Возвращаемое значение:

тип объекта | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Типы объектов и интерфейсы...](objtypes.html)

Примечания:

1\. Параметр paramType может принимать значения ALLPARAM, SHEET_ALLPARAM, DOCUMENT_STATE, SPC_TUNING_PARAM.

2\. Возвращаемым значением может быть SPC_OBJ или SPC_DOCUMENT_OBJ.

3\. Вызов метода с нулевыми значениями параметров param и parType позволяет получить тип объекта по его reference.

Подразделы:

(отсутствуют)
