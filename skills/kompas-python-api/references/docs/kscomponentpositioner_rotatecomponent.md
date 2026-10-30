# RotateComponent - Повернуть компонент

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](kscomponentpositioner_setaxis.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_prepare.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

BOOL RotateComponent (double angl);

Синтаксис COM:

BOOL RotateComponent (double angl);

Входные параметры:

angl | \- угол поворота компоненты, рад.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Перед началом вращения нужно задать ось вращения. Это может быть ось или прямолинейное ребро. Начало перемещения определяется вызовом метода [Prepare](kscomponentpositioner_prepare.html) с типом pnRotate. Окончание перемещения определяется вызовом метода [Finish](kscomponentpositioner_finish.html). Между ними может быть сколько угодно вызовов RotateComponent.

Подразделы:

(отсутствуют)
