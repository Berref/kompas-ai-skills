# topolgyIncluded - Признак, определяющий, включать ли топологию модели при экспорте

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Конвертация в дополнительные форматы (Интерфейсы ksAdditionFormatParam, IAdditionFormatParam) ](ksadditionformatparam.html) > [IAdditionFormatParam - свойства ](ksadditionformatparam_props.html) |  Scroll [ [ [ ](ksadditionformatparam_methods.html "К следующему разделу")](ksadditionformatparam_props.html "На уровень выше")](ksadditionformatparam_textexportform.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksadditionformatparam.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- включить топологию,  
---|---  
FALSE | \- не включать топологию.  
  
Синтаксис Automation:

topolgyIncluded = iAdditionFormatParam.topolgyIncluded | Получить свойство([* ](1.html))  
---|---  
iAdditionFormatParam.topolgyIncluded = topolgyIncluded | Установить свойство ([* ](1.html))  
topolgyIncluded = iAdditionFormatParam.GetTopolgyIncluded() | Получить свойство ([**](2.html))  
iAdditionFormatParam.SetTopolgyIncluded(topolgyIncluded) | Установить свойство ([**](2.html))  
  
Примечание:

Свойство используется при записи в формат IGES.

Подразделы:

(отсутствуют)
