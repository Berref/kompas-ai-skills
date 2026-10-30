# insFrgType - Признак связи объекта с внешним фрагментом

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) > [Параметры объектов спецификации ](ck1727663.html) > [Объект спецификации (Интерфейс ksSpcObjParam) ](ksspcobjparam.html) > [ksSpcObjParam - свойства ](ksspcobjparam_props.html) |  Scroll [ [ [ ](ksspcobjparam_ispoln.html "К следующему разделу")](ksspcobjparam_props.html "На уровень выше")](ksspcobjparam_getdocarr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcobjparam.html)

Тип данных: short

Значения свойства:

0 | \- объект создан непосредственно в документе,  
---|---  
1 | \- объект "пришел" в документ из вставки фрагмента,  
2 | \- объект, полученный из вставки фрагмента, редактировался пользователем вручную.  
  
Синтаксис Automation:

insFrgType = iSpcObjParam.insFrgType | Получить свойство ([* ](1.html))  
---|---  
insFrgType = iSpcObjParam.GetInsFrgType() | Получить свойство ([**](2.html))  
  
Примечание:

Свойство только для чтения.

Подразделы:

(отсутствуют)
