# Finish - Завершить перемещение компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](kscomponentpositioner_movecomponent.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

BOOL Finish();

Синтаксис COM:

BOOL Finish();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Начало перемещения определяется вызовом метода [Prepare](kscomponentpositioner_prepare.html). Между ними может быть сколько угодно вызовов [MoveComponent](kscomponentpositioner_movecomponent.html) или [RotateComponent](kscomponentpositioner_rotatecomponent.html) в зависимости от указанного [типа перемещения](positioner_type.html).

Подразделы:

(отсутствуют)
