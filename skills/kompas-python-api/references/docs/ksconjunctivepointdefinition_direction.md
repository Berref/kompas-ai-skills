# Direction - Направление

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Интерфейсы объекта “Присоединительная точка”ksConjunctivePointDefinition, IConjunctivePointDefinition ](ksconjunctivepointdefinition.html) > [IConjunctivePointDefinition - свойства ](ksconjunctivepointdefinition_props.html) |  Scroll [ [ [ ](ksconjunctivepointdefinition_methods.html "К следующему разделу")](ksconjunctivepointdefinition_props.html "На уровень выше")](ksconjunctivepointdefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksconjunctivepointdefinition.html)

Тип данных: BOOL

Синтаксис Automation:

Direction = iObject.Direction | Получить свойство([* ](1.html))  
---|---  
iObject.Direction = Direction | Установить свойство ([* ](1.html))  
Direction = iObject.GetDirection() | Получить свойство ([**](2.html))  
iObject.SetDirection (Direction) | Установить свойство ([**](2.html))  
  
Значения свойства:

TRUE | \- прямое направление,  
---|---  
FALSE | \- обратное направление.  
  
Примечание:

Позволяет задать конкретное направление вектора. Направление вектора в присоединительной точке зависит от выбора опорного объекта [SetEdge](ksconjunctivepointdefinition_setedge.html).

Подразделы:

(отсутствуют)
