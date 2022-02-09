#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

#include "Tracy.hpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace {
    // Naive exponential method to keep app busy
    int GetFibonacci(unsigned int nth) {
        if (nth < 2) {
            return 1;
        }
        return GetFibonacci(nth - 1) + GetFibonacci(nth - 2);
    }
}

namespace winrt::TracyTest::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    void MainPage::ZoneScopedClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        ZoneScoped;

        GetFibonacci(35);
    }

    void MainPage::ZoneScopedNClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        ZoneScopedN("Named scope");

        GetFibonacci(40);
    }

    void MainPage::FrameMarkClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        static constexpr char s_frameName[] = "Frame name";
        FrameMarkStart(s_frameName);

        GetFibonacci(45);

        FrameMarkEnd(s_frameName);
    }
}
