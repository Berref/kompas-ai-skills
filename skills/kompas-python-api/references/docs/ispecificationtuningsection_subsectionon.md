# SubsectionOn - Деление на подразделы включено

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuningSection ](ispecificationtuningsection.html) > [ISpecificationTuningSection - свойства ](ispecificationtuningsection_props.html) |  Scroll [ [ [ ](ispecificationtuningsection_subsections.html "К следующему разделу")](ispecificationtuningsection_props.html "На уровень выше")](ispecificationtuningsection_sortobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuningsection.html)

Тип данных: BOOL

Синтаксис Automation:

SubsectionOn = iObject.SubsectionOn | Получить свойство ([* ](1.html))  
---|---  
iObject.SubsectionOn = SubsectionOn | Установить свойство ([* ](1.html))  
SubsectionOn = iObject.GetSubsectionOn() | Получить свойство ([**](2.html))  
iObject.SetSubsectionOn (SubsectionOn) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SubsectionOn (&SubsectionOn) | Получить свойство  
---|---  
iObject->put_SubsectionOn (SubsectionOn) | Установить свойство  
  
Значения свойства:

TRUE | \- деление на подразделы включено,  
---|---  
FALSE | \- деление на подразделы выключено.  
  
Примечание:

Позволяет включать и отключать деление раздела на подразделы. Если деление на подразделы включено, объекты внутри раздела будут располагаться с учетом порядка подраздела. Подразделы располагаются в разделе в порядке возрастания номеров.

Подразделы:

(отсутствуют)
