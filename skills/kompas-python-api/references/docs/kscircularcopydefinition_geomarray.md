# geomArray - Признак использования геометрического копирования

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по концентрической сетке (Интерфейсы ksCircularCopyDefinition, ICopyCircularDefinition) ](kscircularcopydefinition.html) > [ICopyCircularDefinition - свойства ](kscircularcopydefinition_props.html) |  Scroll [ [ [ ](kscircularcopydefinition_inverce.html "К следующему разделу")](kscircularcopydefinition_props.html "На уровень выше")](kscircularcopydefinition_factor2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularcopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- использовать геометрическое копирование. Содержимое операций источников (грани, ребра) копируется без пересчета. В простых случаях операция ускоряется, но возможны ошибки при копировании скруглений и фасок на криволинейных поверхностях,  
---|---  
FALSE | \- при копировании все операции-источники строятся заново, т.е. производится полноценный расчет.  
  
Синтаксис Automation:

geomArray = iCircularCopyDefinition.geomArray | Получить свойство([* ](1.html))  
---|---  
iCircularCopyDefinition.geomArray = geomArray | Установить свойство ([* ](1.html))  
iCircularCopyDefinition.GetGeomArray() | Получить свойство ([**](2.html))  
iCircularCopyDefinition.SetGeomArray( geomArray) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
