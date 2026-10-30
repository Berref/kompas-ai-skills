# treeNeedRebuild - Необходимость перестроения дерева при изменении его состава

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_windowneedrebuild.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_shadedwireframe.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- разрешить перестраивать дерево,  
---|---  
FALSE | \- запретить перестраивать дерево.  
  
Синтаксис:

treeNeedRebuild = iDocument3D.treeNeedRebuild | Получить свойство([* ](1.html))  
---|---  
iDocument3D.treeNeedRebuild = treeNeedRebuild | Установить свойство ([* ](1.html))  
treeNeedRebuild = iDocument3D.GetTreeNeedRebuild() | Получить свойство ([**](2.html))  
iDocument3D.SetTreeNeedRebuild (treeNeedRebuild) | Установить свойство ([**](2.html))  
  
Примечания:

1\. Так как после вызова [ksEntity::Update](ksentity_update.html) у любого объекта модель будет перестраиваться, то для ускорения при перестроении группы объектов, кроме закрытия самого перестроения [ksPart::needRebuild](kspart_needrebuild.html), можно также закрыть отрисовку дерева, если она не нужна.

2\. При использовании данного свойства нужно запоминать его значение и после окончания работы с ним возвращать его в первоначальное состояние.

Подразделы:

(отсутствуют)
