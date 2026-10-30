////////////////////////////////////////////////////////////////////////////////
//
// APropertyUserControlEvent  - обработчик событий от пользоваиельского контрола
// ATreeCtrlEvent             - обработчик событий от ocx дерева
// AToolBarCtrlEvent          - обработчик событий от ocx toolbar'a
// AContextMenuEvent          - обработчик событий от ocx для меню
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _APROPUSEREVENT_H
#define _APROPUSEREVENT_H

#ifndef _ABASEEVENT_H
#include "ABaseEvent.h"
#endif
#include <afxcview.h>

#include "PArray.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000     


class ATreeCtrlEvent;
class AToolBarCtrlEvent;
class AContextMenuEvent;


//-----------------------------------------------------------------------------
//
// ---
class ATreeViewEventCallBack
{
public:
  // АВВ К11   virtual void BeforeLabelEdit ( short * Cancel );
  // АВВ К11   virtual void AfterLabelEdit  ( short * Cancel, BSTR * NewString );
  virtual void OnExpandOrCollapse(IPropertyTreeNodePtr Node, bool collapse) {}
  virtual void OnSelectNodes(const VARIANT& Nodes, bool selected) {}
  virtual void OnMenuCommand(long Id) {}
  virtual void OnNodeDblClick(IPropertyTreeNodePtr Node) {}
  virtual void OnBeginEditText(IPropertyTreeNodePtr Node) {}
  virtual void OnNodeDragStarted(IPropertyTreeNodePtr Node) {}
  virtual void OnNodeDragOver(IPropertyTreeNodePtr NotifyNode, IPropertyTreeNodePtr DragNode, bool CtrlPressed, bool RequiredDropAfter) {}
  virtual void OnNodeDragDroped(IPropertyTreeNodePtr NotifyNode, IPropertyTreeNodePtr DragNode, bool CtrlPressed) {}
  virtual void OnContextMenuRequest(IPropertyTreeNodePtr Node) {}
};


//-----------------------------------------------------------------------------
// ATreeViewEvent  - обработчик событий от ocx дерева
// ---
class ATreeViewEvent : public ABaseEvent
{
  ATreeViewEventCallBack& m_obj;
public:
  ATreeViewEvent(IPropertyTreePtr& tree, ATreeViewEventCallBack& obj);
  virtual ~ATreeViewEvent();

protected:
  // АВВ К11   afx_msg void BeforeLabelEdit ( short * Cancel );
  // АВВ К11   afx_msg void AfterLabelEdit  ( short * Cancel, BSTR * NewString );
  afx_msg void Collapse(LPDISPATCH Node);
  afx_msg void Expand(LPDISPATCH Node);
  afx_msg void NodeDblClick(LPDISPATCH Node);
  afx_msg void BeginTextEdit(LPDISPATCH Node);
  afx_msg void EndTextEdit(LPDISPATCH Node);
  afx_msg void SelectNodes(const VARIANT& Nodes);
  afx_msg void UnSelectNodes(const VARIANT& Nodes);
  afx_msg void NodeDragStarted(LPDISPATCH Node);
  afx_msg void NodeDragOver(LPDISPATCH NotifyNode, LPDISPATCH DragNode, BOOL IsCtrlPressed, BOOL RequiredDropAfter);
  afx_msg void NodeDragDroped(LPDISPATCH NotifyNode, LPDISPATCH DragNode, BOOL IsCtrlPressed);
  afx_msg void ContextMenuRequest(LPDISPATCH Node);

  // АВВ К11   afx_msg void NodeCheck       ( struct INode * Node );

  DECLARE_EVENTSINK_MAP()
};

#endif 
