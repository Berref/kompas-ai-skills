# PropertyParam - Структура параметров свойства отображаемого в окне свойств

[Структуры параметров и константы](3d_define.html) > [Структуры параметров окна Свойства ](bk1844167.html) |  Scroll [ [ [ ](bk1803360.html "К следующему разделу")](bk1844167.html "На уровень выше")](bk1844167.html "К предыдущему разделу")  
---|---  
  
int | propertyType | Тип свойства из перечисления [ksObjectPropertyControlTypeEnum,](ksobjectpropertycontroltypeenum.html)  
---|---|---  
int | propertyId; | Идентификатор свойства - используется для загрузки имени и параметров свойства из ресурсов,  
HINSTANCE | propertyInstance; | Модуль ресурсов для загрузки параметров свойства (имя, список значений...),  
LPOLESTR | displayPropertyName; | Отображаемое имя свойства (необязательное),  
VARIANT | propertyValue; | Текущее значение,  
double | propertyMinValue; | Минимальное значение,  
double | propertyMaxValue; | Максимальное значение,  
int | isDefCpyProp; | Будет отмечено для копирования,  
int | enable; | Признак доступности для изменения,  
int | emptyValue; | Значение не задано,  
VARIANT | additionalData; | Дополнительные данные для свойства,  
LPOLESTR | additionalText; | Дополнительный текст,  
int | summList; | TRUE - объединять списки, FALSE - пересекать списки.  
  
Примечание:

Поля propertyType, propertyId и propertyInstance являются обязательными для заполнения. Остальные поля заполняются в зависимости от типа контрола.

Подразделы:

(отсутствуют)
