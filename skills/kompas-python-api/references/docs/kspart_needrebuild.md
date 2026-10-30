# needRebuild - Необходимость перестроения объектов при изменении их свойств

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - свойства ](kspart_props.html) |  Scroll [ [ [ ](kspart_propertyobjecteditable.html "К следующему разделу")](kspart_props.html "На уровень выше")](kspart_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- При вызове метода [ksEntity](ksentity_update.html) после установки модельному объекту новых свойств модель будет перестроена,  
---|---  
FALSE | \- модель перестраиваться не будет.  
  
Синтаксис Automation:

needRebuild = iPart.needRebuild | Получить свойство ([* ](1.html))  
---|---  
iPart.needRebuild = needRebuild | Установить свойство ([* ](1.html))  
needRebuild = iPart.GetNeedRebuild() | Получить свойство ([**](2.html))  
iPart.SetNeedRebuild (needRebuild) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

needRebuild = iPart->GetNeedRebuild() | Получить свойство  
---|---  
iPart->SetNeedRebuild (needRebuild) | Установить свойство  
  
Примечания:

Если необходимо изменить свойства нескольких объектов, то достаточно одного перестроения модели после установки новых свойств всем модельным объектам. Для этого перед изменением свойств объектов нужно установить значение этого свойства равным FALSE, поменять свойства объектов и вызвать у каждого из них метод [ksEntity::Update](ksentity_update.html), а затем вызвать метод [ksPart::RebuildModelEx](kspart_rebuildmodelex.html) с параметром redraw равным TRUE.

Если значению данного свойства установлено FALSE, то после каждого вызова метода ksEntity::Update у объекта модель будет перестраиваться.

Подразделы:

(отсутствуют)
