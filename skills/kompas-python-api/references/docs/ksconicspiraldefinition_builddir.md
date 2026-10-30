# buildDir - Направление построения спирали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Коническая спираль (Интерфейсы ksConicSpiralDefinition и IConicSpiralDefinition) ](ksconicspiraldefinition.html) > [IConicSpiralDefinition - свойства ](ksconicspiraldefinition_props.html) |  Scroll [ [ [ ](ksconicspiraldefinition_buildmode.html "К следующему разделу")](ksconicspiraldefinition_props.html "На уровень выше")](ksconicspiraldefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksconicspiraldefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- нормальное (совпадающее с положительным направлением нормали к базовой плоскости спирали),  
---|---  
FALSE | \- обратное.  
  
Синтаксис Automation:

buildDir = iConicSpiral.buildDir | Получить свойство ([* ](1.html))  
---|---  
iConicSpiral.buildDir = buildDir | Установить свойство ([* ](1.html))  
buildDir = iConicSpiral.GetBuildDir() | Получить свойство ([**](2.html))  
iConicSpiral.SetBuildDir(buildDir) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
