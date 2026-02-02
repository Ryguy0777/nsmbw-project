#pragma once

template <class T, auto N, class S = std::size_t>
class cArray_c
{
public:
    // Type Aliases
    // ^^^^^^

    using value_type = T;
    using size_type = S;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;

public:
    // Instance Methods
    // ^^^^^^

    constexpr reference at(size_type index) noexcept
    {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr const_reference at(size_type index) const noexcept
    {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr reference operator[](size_type index) noexcept
    {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr const_reference operator[](size_type index) const noexcept
    {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr pointer data() noexcept
    {
        return m_data;
    }

    constexpr const_pointer data() const noexcept
    {
        return m_data;
    }

    constexpr size_type size() const noexcept
    {
        return static_cast<size_type>(N);
    }

    constexpr pointer begin() noexcept
    {
        return m_data;
    }

    constexpr const_pointer begin() const noexcept
    {
        return m_data;
    }

    constexpr pointer end() noexcept
    {
        return m_data + size();
    }

    constexpr const_pointer end() const noexcept
    {
        return m_data + size();
    }

    constexpr size_type index(const_pointer ptr) const noexcept
    {
        return static_cast<size_type>(ptr - m_data);
    }

    constexpr size_type index(const_reference ref) const noexcept
    {
        return static_cast<size_type>(&ref - m_data);
    }

public:
    // Instance Variables
    // ^^^^^^

    T m_data[static_cast<std::size_t>(N)];
};