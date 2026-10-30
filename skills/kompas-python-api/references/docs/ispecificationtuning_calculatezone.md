# CalculateZone - Режим расчета зон

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_copyspcobjectoncopygeometry.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_calculateposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

CalculateZone = iObject.CalculateZone | Получить свойство ([* ](1.html))  
---|---  
iObject.CalculateZone = CalculateZone | Установить свойство ([* ](1.html))  
CalculateZone = iObject.GetCalculateZone() | Получить свойство ([**](2.html))  
iObject.SetCalculateZone (CalculateZone) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CalculateZone (&CalculateZone) | Получить свойство  
---|---  
iObject->put_CalculateZone (CalculateZone) | Установить свойство  
  
Значения свойства:

TRUE | \- при автоматической простановке номеров позиций происходит обновление номеров зон чертежа,  
---|---  
FALSE | \- зоны не обновляются.  
  
Примечание:

Позволяет включить или отключить передачу в спецификацию обозначений зон сборочного чертежа, в которых находятся позиционные линии-выноски объектов. Если передача разрешена, она происходит при синхронизации чертежа со спецификацией.

Подразделы:

(отсутствуют)
