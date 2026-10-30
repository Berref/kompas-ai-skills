# ModelLocalCSSetActive - При создании ЛСК назначать ее текущей СК

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ISystemSettings ](isystemsettings.html) > [ISystemSettings - свойства ](isystemsettings_props.html) |  Scroll [ [ [ ](isystemsettings_modelsmoothmotion.html "К следующему разделу")](isystemsettings_props.html "На уровень выше")](isystemsettings_modellocalcscreateinabsolutecs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isystemsettings.html)

Тип данных: BOOL

Значение свойства:

TRUE | \- новая локальная система координат станет текущей,  
---|---  
FALSE | \- текущей останется старая СК.  
  
Синтаксис Automation:

ModelLocalCSSetActive = iObject.ModelLocalCSSetActive | Получить свойство ([* ](1.html))  
---|---  
iObject.ModelLocalCSSetActive = ModelLocalCSSetActive | Установить свойство ([* ](1.html))  
ModelLocalCSSetActive = iObject.GetModelLocalCSSetActive() | Получить свойство ([**](2.html))  
iObject.SetModelLocalCSSetActive(ModelLocalCSSetActive) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ModelLocalCSSetActive (&ModelLocalCSSetActive) | Получить свойство,  
---|---  
iObject->put_ModelLocalCSSetActive (&ModelLocalCSSetActive) | Установить свойство.  
  
Подразделы:

(отсутствуют)
