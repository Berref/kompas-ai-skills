# formatBinary - Признак, определяющий тип файла (двоичный или текстовый)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Конвертация в дополнительные форматы (Интерфейсы ksAdditionFormatParam, IAdditionFormatParam) ](ksadditionformatparam.html) > [IAdditionFormatParam - свойства ](ksadditionformatparam_props.html) |  Scroll [ [ [ ](ksadditionformatparam_length.html "К следующему разделу")](ksadditionformatparam_props.html "На уровень выше")](ksadditionformatparam_format.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksadditionformatparam.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- двоичный формат,  
---|---  
FALSE | \- текстовый формат.  
  
Синтаксис Automation:

formatBinary = iAdditionFormatParam.formatBinary | Получить свойство([* ](1.html))  
---|---  
iAdditionFormatParam.formatBinary = formatBinary | Установить свойство ([* ](1.html))  
formatBinary = iAdditionFormatParam.GetFormatBinary() | Получить свойство ([**](2.html))  
iAdditionFormatParam.SetFormatBinary(formatBinary) | Установить свойство ([**](2.html))  
  
Примечание:

Свойство используется при записи в форматы XT, X_B, STL.

Подразделы:

(отсутствуют)
