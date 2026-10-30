# autoDefinDr - Автоопределение диаметра

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Условное изображение резьбы (Интерфейсы ksThreadDefinition, IThreadDefinition) ](ksthreaddefinition.html) > [IThreadDefinition - свойства ](ksthreaddefinition_props.html) |  Scroll [ [ [ ](ksthreaddefinition_dr.html "К следующему разделу")](ksthreaddefinition_props.html "На уровень выше")](ksthreaddefinition_alllength.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksthreaddefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- номинальный диаметр резьбы [dr](ksthreaddefinition_dr.html) не зависит от значения указанного пользователем,  
---|---  
FALSE | \- номинальный диаметр резьбы задается пользователем.  
  
Синтаксис Automation:

autoDefinDr = iThreadDefinition.autoDefinDr | Получить свойство ([* ](1.html))  
---|---  
iThreadDefinition.autoDefinDr = autoDefinDr | Установить свойство ([* ](1.html))  
iThreadDefinition.GetAutoDefinDr() | Получить свойство ([**](2.html))  
iThreadDefinition.SetAutoDefinDr(autoDefinDr) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
