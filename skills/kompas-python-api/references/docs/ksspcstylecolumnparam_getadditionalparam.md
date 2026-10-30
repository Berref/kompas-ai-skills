# GetAdditionalParam - Получить указатель на интерфейс дополнительной информации ksRecordTypeAttrParam или ksNumberTypeAttrParam

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) > [Колонка спецификации ](ck1871091.html) > [Стиль колонки (Интерфейс ksSpcStyleColumnParam) ](ksspcstylecolumnparam.html) > [ksSpcStyleColumnParam - методы ](ksspcstylecolumnparam_methods.html) |  Scroll [ [ [ ](ksspcstylecolumnparam_init.html "К следующему разделу")](ksspcstylecolumnparam_methods.html "На уровень выше")](ksspcstylecolumnparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcstylecolumnparam.html)

Синтаксис Automation:

LPDISPATCH GetAdditionalParam();

Возвращаемое значение:

| \- указатель на интерфейс [ksRecordTypeAttrParam](ksrecordtypeattrparam.html) или [ksNumberTypeAttrParam](ksnumbertypeattrparam.html)  
---|---  
  
Примечание:

Тип возвращаемого интерфейса зависит от типа значения в колонке [ksSpcStyleColumnParam::typeVal:](ksspcstylecolumnparam_typeval.html)

Тип значения | Интерфейс  
---|---  
SPC_RECORD | ksRecordTypeAttrParam  
DOUBLE_ATTR_TYPE | ksNumberTypeAttrParam  
LINT_ATTR_TYPE | ksNumberTypeAttrParam  
  
Подразделы:

(отсутствуют)
