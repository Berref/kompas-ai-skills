# factor1 - Признак полного шага копирования вдоль первой оси

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по параллельной сетке (Интерфейсы ksMeshPartArrayDefinition, IMeshPartArrayDefinition) ](ksmeshpartarraydefinition.html) > [ksMeshPartArrayDefinition - свойства ](ksmeshpartarraydefinition_props.html) |  Scroll [ [ [ ](ksmeshpartarraydefinition_factor2.html "К следующему разделу")](ksmeshpartarraydefinition_props.html "На уровень выше")](ksmeshpartarraydefinition_count2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshpartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step1](ksmeshpartarraydefinition_count1.html) устанавливает расстояние между крайними элементами вдоль 1-ой оси,  
---|---  
FALSE | \- свойство step1 устанавливает расстояние между соседними элементами вдоль 1-ой оси.  
  
Синтаксис Automation:

factor1 = iMeshArray.factor1 | Получить свойство([* ](1.html))  
---|---  
iMeshArray.factor1 = factor1 | Установить свойство ([* ](1.html))  
factor1 = iMeshArray.GetFactor1() | Получить свойство ([**](2.html))  
iMeshArray.SetFactor1(factor1) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
