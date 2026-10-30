# StepFactor - Способ задания шага

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс ICopyObjectParam ](icopyobjectparam.html) > [ICopyObjectParam - свойства ](icopyobjectparam_props.html) > [YNew - Координата новой точки привязки объекта по оси Y ](icopyobjectparam_ynew.html) > [Интерфейс ICurveCopyObjectParam ](icurvecopyobjectparam.html) > [ICurveCopyObjectParam - свойства ](icurvecopyobjectparam_props.html) |  Scroll [ [ [ ](icurvecopyobjectparam_turntonormal.html "К следующему разделу")](icurvecopyobjectparam_props.html "На уровень выше")](icurvecopyobjectparam_step.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvecopyobjectparam.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- шаг задан между крайними копиями,  
---|---  
FALSE | \- шаг задан между соседними копиями.  
  
Синтаксис Automation:

StepFactor = Object.StepFactor | Получить свойство ([* ](1.html))  
---|---  
Object.StepFactor = StepFactor | Установить свойство ([**](2.html))  
StepFactor = Object.GetStepFactor() | Получить свойство ([**](2.html))  
Object.SetStepFactor( StepFactor ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StepFactor( &StepFactor ) | Получить свойство  
---|---  
Object.put_StepFactor( StepFactor ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать способ задания шага.

Подразделы:

(отсутствуют)
