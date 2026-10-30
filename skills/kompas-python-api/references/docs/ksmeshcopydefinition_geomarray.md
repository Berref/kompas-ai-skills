# geomArray - Признак использования геометрического копирования

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по параллелограммной сетке( Интерфейсы ksMeshCopyDefinition и ICopyMeshDefinition) ](ksmeshcopydefinition.html) > [ICopyMeshDefinition - свойства ](ksmeshcopydefinition_props.html) |  Scroll [ [ [ ](ksmeshcopydefinition_insideflag.html "К следующему разделу")](ksmeshcopydefinition_props.html "На уровень выше")](ksmeshcopydefinition_factor2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshcopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- использовать геометрическое копирование. Содержимое операций-источников (грани, ребра) копируется без пересчета. В простых случаях операция ускоряется, но возможны ошибки при копировании скруглений и фасок на криволинейных поверхностях,  
---|---  
FALSE | \- при копировании все операции-источники строятся заново, т.е. производится полноценный расчет.  
  
Синтаксис Automation:

geomArray = ICopyMeshDefinition.geomArray | Получить свойство([* ](1.html))  
---|---  
ICopyMeshDefinition.geomArray = geomArray | Установить свойство ([* ](1.html))  
geomArray = ICopyMeshDefinition.GetGeomArray() | Получить свойство ([**](2.html))  
ICopyMeshDefinition.SetGeomArray( geomArray) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
