#pragma once

#include "MainPage.g.h"

namespace winrt::TracyTest::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void ZoneScopedClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void ZoneScopedNClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void FrameMarkClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::TracyTest::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
