////////////////////////////////////////////////////////////////////////////////
//
// APropertyUserControlEvent  - обработчик событий от пользовательского контрола
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

//#include "cPropMen.h"
#include "aPropUserEvent.h"
#include "Resource.h"

////////////////////////////////////////////////////////////////////////////////
//
// ATreeViewEvent  - обработчик событий от ocx дерева
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
// Конструктор
// ---
ATreeViewEvent::ATreeViewEvent(IPropertyTreePtr& tree, ATreeViewEventCallBack& obj)
  : ABaseEvent(tree, DIID_ksPropertyTreeNotify)
  , m_obj(obj)
{
  Advise();
}

//-------------------------------------------------------------------------------
// Деструктор
// ---
ATreeViewEvent::~ATreeViewEvent()
{
}

//-------------------------------------------------------------------------------
// Карта сообщений
// ---
BEGIN_EVENTSINK_MAP(ATreeViewEvent, ABaseEvent)

  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeSelectNodes, SelectNodes, VTS_VARIANT)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeUnselectNodes, UnSelectNodes, VTS_VARIANT)

  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeCollapseNode, Collapse, VTS_DISPATCH)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeExpandNode, Expand, VTS_DISPATCH)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeNodeDblClick, NodeDblClick, VTS_DISPATCH)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeNodeBeginTextEdit, BeginTextEdit, VTS_DISPATCH)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeNodeEndTextEdit, EndTextEdit, VTS_DISPATCH)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeNodeDragStarted, NodeDragStarted, VTS_DISPATCH)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeNodeDragOver, NodeDragOver, VTS_DISPATCH VTS_DISPATCH VTS_BOOL VTS_BOOL)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeNodeDragDroped, NodeDragDroped, VTS_DISPATCH VTS_DISPATCH VTS_BOOL)
  ON_EVENT(ATreeViewEvent, (unsigned int)-1, ksTreeContextMenuRequest, ContextMenuRequest, VTS_DISPATCH)
END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::Collapse(LPDISPATCH Node)
{
  if (Node)
    m_obj.OnExpandOrCollapse(Node, true);
}


//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::Expand(LPDISPATCH Node)
{
  if (Node)
    m_obj.OnExpandOrCollapse(Node, false);
}


//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::SelectNodes(const VARIANT& Nodes)
{
  m_obj.OnSelectNodes(Nodes, true);
}

//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::UnSelectNodes(const VARIANT& Nodes)
{
  m_obj.OnSelectNodes(Nodes, false);
}

//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::NodeDragStarted(LPDISPATCH Node)
{
  m_obj.OnNodeDragStarted(Node);
}

//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::NodeDragOver(LPDISPATCH NotifyNode, LPDISPATCH DragNode, BOOL IsCtrlPressed, BOOL RequiredDropAfter)
{
  m_obj.OnNodeDragOver(NotifyNode, DragNode, !!IsCtrlPressed, !!RequiredDropAfter);
}

//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::NodeDragDroped(LPDISPATCH NotifyNode, LPDISPATCH DragNode, BOOL IsCtrlPressed)
{
  m_obj.OnNodeDragDroped(NotifyNode, DragNode, !!IsCtrlPressed);
}

//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::ContextMenuRequest(LPDISPATCH Node)
{
  m_obj.OnContextMenuRequest(Node);
}


//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::NodeDblClick(LPDISPATCH Node)
{
  m_obj.OnNodeDblClick(Node);
}

//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::BeginTextEdit(LPDISPATCH Node)
{
  m_obj.OnBeginEditText(Node);
}

//-----------------------------------------------------------------------------
/// 
// ---
void ATreeViewEvent::EndTextEdit(LPDISPATCH Node)
{
}