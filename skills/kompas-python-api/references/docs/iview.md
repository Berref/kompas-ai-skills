# Интерфейс IView

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) |  Scroll [ [ [ ](iview_props.html "К следующему разделу")](idrawingobject_methods.html "На уровень выше")](ilayer_visible.html "К предыдущему разделу")  
---|---  
  
Интерфейс вида графического документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IView](iview.html)

[IViewDesignation](iviewdesignation.html)

[IDrawingContainer](idrawingcontainer.html)

[IBuildingContainer](ibuildingcontainer.html)

[ISymbols2DContainer](isymbols2dcontainer.html)

[IBreakViewParam](ibreakviewparam.html)

[ICutViewParam](icutviewparam.html)

[IView1](iview1.html)

Описание:

Типы видов описаны в перечислении [LtViewType](ltviewtype.html).

В графическом документе всегда присутствует системный вид, который формируется автоматически при создании документа, и может быть только один. В документе типа Фрагмент может быть только один вид - системный.

Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительные интерфейсы вида:

•Интерфейс обозначения вида [IViewDesignation](iviewdesignation.html).

•Интерфейс контейнера объектов вида графического документа [IDrawingContainer](idrawingcontainer.html).

•Интерфейс контейнера объектов СПДС [IBuildingContainer](ibuildingcontainer.html).

•Интерфейс контейнера условных обозначений [ISymbols2DContainer](isymbols2dcontainer.html).

•Интерфейс параметров разрыва вида [IBreakViewParam](ibreakviewparam.html). Этот интерфейс может быть получен для видов всех типов, кроме системного.

•Интерфейс параметров разреза вида [ICutViewParam](icutviewparam.html). Этот интерфейс может быть получен для видов всех типов, кроме системного.

•Интерфейс для получения коллекции ЛСК и признака редактирования макроэлемента [IView1](iview1.html).

Примечание:

Данный интерфейс можно получить следующими способами:

•через коллекцию видов [IViews](iviews.html),

•с помощью свойства [IViews::View](iviews_view.html), [IViews::ViewByNumber](iviews_viewbynumber.html) или метода [IViews::Add](iviews_add.html), либо с помощью свойства [IDrawingObjects::Item](idrawingobjects_item.html) с последующим приведением к данному интерфейсу с помощью метода IUnknown QueryInterface,

•от интерфейса группы слоев [ILayerGroup](ilayergroup.html) с помощью свойства [ILayerGroup::OwnerView](ilayergroup_ownerview.html),

Подразделы:

[IView - свойства ](iview_props.html)
