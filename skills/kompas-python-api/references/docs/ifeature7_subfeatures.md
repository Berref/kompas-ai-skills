# SubFeatures - Коллекция элементов дерева заданного типа в виде массива SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IFeature7 ](ifeature7.html) > [IFeature7 - свойства ](ifeature7_props.html) |  Scroll [ [ [ ](ifeature7_updatestamp.html "К следующему разделу")](ifeature7_props.html "На уровень выше")](ifeature7_state.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeature7.html)

Тип данных: VARIANT

Синтаксис Automation:

SubFeatures = Object.SubFeatures( treeType, through, libObject ) | Получить свойство ([* ](1.html))  
---|---  
SubFeatures = Object. GetSubFeatures ( treeType, through, libObject ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SubFeatures( treeType, through, libObject, &SubFeatures ) | Получить свойство  
---|---  
  
Параметры:

treeType | \- тип дерева из перечисления [ksTreeTypeEnum](kstreetypeenum.html),  
---|---  
through | \- TRUE - выдавать все объекты, даже скрытые,  
libObject | \- TRUE - выдавать содержимое для библиотечного элемента.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
