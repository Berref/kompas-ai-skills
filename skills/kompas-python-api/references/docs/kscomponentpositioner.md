# Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) |  Scroll [ [ [ ](kscomponentpositioner_methods.html "К следующему разделу")](ksdocument3d.html "На уровень выше")](ispecification3d_spcincludepart.html "К предыдущему разделу")  
---|---  
  
Интерфейс управления положением компонентов в сборке.

ksComponentPositioner | \- интерфейс Automation  
---|---  
IComponentPositioner | \- интерфейс COM  
  
Описание:

Сдвиг проводится в плоскости, которая определена относительно сборки. Для сдвига точка захвата должна быть определена в системе координат сдвигаемого компонента, а точка сдвига должна быть в системе координат сборки и преобразована в проекцию на плоскость сдвига. Перед началом сдвига нужно задать плоскость и точку захвата.

Вращение проводится относительно оси, которая задается относительно сборки. Перед началом вращения нужно задать ось вращения. Это может быть ось или прямолинейное ребро. Начало перемещения определяется вызовом метода [Prepare](kscomponentpositioner_prepare.html). Окончание перемещения определяется вызовом метода [Finish](kscomponentpositioner_finish.html). Между ними может быть сколько угодно вызовов [MoveComponent](kscomponentpositioner_movecomponent.html) или [RotateComponent](kscomponentpositioner_rotatecomponent.html) в зависимости от указанного [типа перемещения](positioner_type.html).

Примечание:

Данный интерфейс может быть получен с использованием метода интерфейса [ksDocument3D::ComponentPositioner](ksdocument3d_componentpositioner.html).

Подразделы:

[IComponentPositioner - методы ](kscomponentpositioner_methods.html)
