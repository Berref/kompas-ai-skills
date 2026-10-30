# factor2 - Признак полного шага копирования вдоль второй оси

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по параллельной сетке (Интерфейсы ksMeshPartArrayDefinition, IMeshPartArrayDefinition) ](ksmeshpartarraydefinition.html) > [ksMeshPartArrayDefinition - свойства ](ksmeshpartarraydefinition_props.html) |  Scroll [ [ [ ](ksmeshpartarraydefinition_insideflag.html "К следующему разделу")](ksmeshpartarraydefinition_props.html "На уровень выше")](ksmeshpartarraydefinition_factor1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshpartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step2](ksmeshpartarraydefinition_step2.html) устанавливает расстояние между крайними элементами вдоль второй оси,  
---|---  
FALSE | \- свойство step2 устанавливает расстояние между соседними элементами вдоль второй оси.  
  
Синтаксис Automation:

factor2 = iMeshArray.factor2 | Получить свойство([* ](1.html))  
---|---  
iMeshArray.factor2 = factor2 | Установить свойство ([* ](1.html))  
factor2 = iMeshArray.GetFactor2() | Получить свойство ([**](2.html))  
iMeshArray.SetFactor2(factor2) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
