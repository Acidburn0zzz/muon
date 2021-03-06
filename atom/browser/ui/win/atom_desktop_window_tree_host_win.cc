// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/browser/ui/win/atom_desktop_window_tree_host_win.h"

#include "atom/browser/ui/win/message_handler_delegate.h"

namespace atom {

AtomDesktopWindowTreeHostWin::AtomDesktopWindowTreeHostWin(
    MessageHandlerDelegate* delegate,
    views::internal::NativeWidgetDelegate* native_widget_delegate,
    views::DesktopNativeWidgetAura* desktop_native_widget_aura)
        : views::DesktopWindowTreeHostWin(native_widget_delegate,
                                          desktop_native_widget_aura),
          delegate_(delegate) {
}

AtomDesktopWindowTreeHostWin::~AtomDesktopWindowTreeHostWin() {
}
/** Route Windows messages to delegate (NativeWindowViews)
 *  \see src/electron/atom/browser/native_window_views_win.cc
 *  \see src/electron/atom/browser/native_window_views.cc
 */
bool AtomDesktopWindowTreeHostWin::PreHandleMSG(
    UINT message, WPARAM w_param, LPARAM l_param, LRESULT* result) {
  return delegate_->PreHandleMSG(message, w_param, l_param, result);
}

/** Override the client area inset
 *  Returning true forces a border of 0 for frameless windows
 */
bool AtomDesktopWindowTreeHostWin::GetClientAreaInsets(
    gfx::Insets* insets) const {
  return !HasFrame();
}

}  // namespace atom
