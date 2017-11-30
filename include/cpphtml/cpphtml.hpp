#ifndef __CPP_HTML_HPP_
#define __CPP_HTML_HPP_

#include <string>
#include <boost/flyweight.hpp>
#include <functional>
#include <type_traits>

namespace cpphtml
{
    struct html_root
    {
        explicit html_root(std::string const &name) :
                name_(name)
        {

        }

        virtual std::string
        to_string() const = 0;

        operator std::string()
        {
            return to_string();
        }

        std::string
        operator()() const
        {
            return to_string();
        }

    protected:
        boost::flyweight<std::string> name_;
    };


    struct attr :
            public html_root
    {
        explicit
        attr(std::string const &name) :
                html_root(name)
        {

        }


        explicit
        attr(std::string const &name, std::string &&value) :
                html_root(name),
                value_func_(
                        [value]()
                        { return value; }
                )
        {

        }

        explicit
        attr(std::string const &name, std::string &value) :
                html_root(name),
                value_func_(
                        [&value]()
                        { return value; }
                )
        {

        }

        template<class V, class = decltype(std::to_string(std::declval<V>()))>
        explicit
        attr(std::string const &name, V &&value) :
                html_root(name),
                value_func_(
                        [&value]()
                        { return std::to_string(value); }
                )
        {

        }

        template<class F, class = typename std::enable_if<
                std::is_same<std::string, typename std::decay<decltype(std::declval<F>()())>::type>::value ||
                std::is_same<char const *, typename std::decay<decltype(std::declval<F>()())>::type>::value
        >::type>
        explicit
        attr(std::string const &name, F func) :
                html_root(name),
                value_func_(std::move(func))
        {

        }

        std::string
        to_string() const override
        {
            if (value_func_)
            {
                std::string value = value_func_();
                std::string res = name_.get() + "=\"";
                for (std::string::size_type i = 0; i < value.length(); ++i)
                {
                    if ('\"' == value.at(i) && (i == 0 || value.at(i - 1) != '\\'))
                    {
                        res.push_back('\\');
                        res.push_back('\"');
                    }
                    else
                    {
                        res.push_back(value.at(i));
                    }
                }

                res += "\"";
                return std::move(res);
            }
            else
            {
                return name_.get();
            }
        }


    protected:
        std::function<std::string()> value_func_;
    };


    struct node :
            public html_root
    {
        explicit node(std::string const &name) :
                html_root(name)
        {

        }

        template<class ...Args>
        explicit
        node(std::string const &name, Args &&...args):
                html_root(name)
        {
            assign(std::forward<Args>(args)...);
        }

        std::string
        to_string() const override
        {
            std::string res;
            if (attrs_.empty() && nodes_.empty())
            {
                res += "<";
                res += name_.get();
                res += " />";
            }
            else
            {
                res += "<";
                res += name_.get();
                for (auto const &v : attrs_)
                {
                    res += " ";
                    res += v();
                }

                if (nodes_.empty())
                {
                    res += " />";
                }
                else
                {
                    res += ">";
                    for (auto const &v : nodes_)
                    {
                        res += v();
                    }
                    res += "</";
                    res += name_.get();
                    res += ">";
                }
            }
            return std::move(res);
        }

    protected:
        template<class T, class ...Args>
        void
        assign(T &&t, Args &&...args)
        {
            assign_impl(std::forward<T>(t));
            assign(std::forward<Args>(args)...);
        }

        template<class T>
        void
        assign(T &&t)
        {
            assign_impl(std::forward<T>(t));
        }

        template<class T>
        void
        assign_impl(T &&t)
        {
            if constexpr(std::is_base_of<attr, typename std::decay<T>::type>::value)
            {
                attrs_.emplace_back(std::move(t));
            }
            else if constexpr (std::is_invocable<T>::value)
            {
                if constexpr(std::is_same<std::string, typename std::decay<decltype(std::declval<T>()())>::type>::value ||
                             std::is_same<char const *, typename std::decay<decltype(std::declval<T>()())>::type>::value)
                {
                    nodes_.emplace_back(std::move(t));
                }
            }
            else if constexpr (std::is_same<std::string, typename std::decay<T>::type>::value)
            {
                nodes_.emplace_back(
                        [&t]()
                        {
                            return t;
                        }
                );
            }
            else if constexpr (std::is_same<char const *, typename std::decay<T>::type>::value)
            {
                std::string str = t;
                nodes_.emplace_back(
                        [str]()
                        {
                            return str;
                        }
                );
            }
            else
            {
                nodes_.emplace_back(
                        [&t]()
                        {
                            return std::to_string(t);
                        }
                );
            }
        }

    protected:
        std::list<std::function<std::string()>> attrs_;
        std::list<std::function<std::string()>> nodes_;
    };

#define NODE_REG(X) template<class ...Args> node X(Args &&...args){return std::move(node(#X, std::forward<Args>(args)...));}
#define ATTR_REG(X) template<class T> attr X##_(T &&t){return std::move(attr(#X, std::forward<T>(t)));}

    inline namespace nodes
    {
        NODE_REG(a)

        NODE_REG(abbr)

        NODE_REG(acronym)

        NODE_REG(address)

        NODE_REG(applet)

        NODE_REG(area)

        NODE_REG(article)

        NODE_REG(aside)

        NODE_REG(audio)

        NODE_REG(b)

        NODE_REG(base)

        NODE_REG(basefont)

        NODE_REG(bdi)

        NODE_REG(bdo)

        NODE_REG(big)

        NODE_REG(blockquote)

        NODE_REG(body)

        NODE_REG(br)

        NODE_REG(button)

        NODE_REG(canvas)

        NODE_REG(caption)

        NODE_REG(center)

        NODE_REG(cite)

        NODE_REG(code)

        NODE_REG(col)

        NODE_REG(colgroup)

        NODE_REG(command)

        NODE_REG(datalist)

        NODE_REG(dd)

        NODE_REG(del)

        NODE_REG(details)

        NODE_REG(dfn)

        NODE_REG(dialog)

        NODE_REG(dir)

        NODE_REG(div)

        NODE_REG(dl)

        NODE_REG(dt)

        NODE_REG(em)

        NODE_REG(embed)

        NODE_REG(fieldset)

        NODE_REG(figcaption)

        NODE_REG(figure)

        NODE_REG(font)

        NODE_REG(footer)

        NODE_REG(form)

        NODE_REG(frame)

        NODE_REG(frameset)

        NODE_REG(h1)

        NODE_REG(h2)

        NODE_REG(h3)

        NODE_REG(h4)

        NODE_REG(h5)

        NODE_REG(h6)

        NODE_REG(head)

        NODE_REG(header)

        NODE_REG(hr)

        NODE_REG(html)

        NODE_REG(i)

        NODE_REG(iframe)

        NODE_REG(img)

        NODE_REG(input)

        NODE_REG(ins)

        NODE_REG(isindex)

        NODE_REG(kbd)

        NODE_REG(keygen)

        NODE_REG(label)

        NODE_REG(legend)

        NODE_REG(li)

        NODE_REG(link)

        NODE_REG(map)

        NODE_REG(mark)

        NODE_REG(menu)

        NODE_REG(menuitem)

        NODE_REG(meta)

        NODE_REG(meter)

        NODE_REG(nav)

        NODE_REG(noframes)

        NODE_REG(noscript)

        NODE_REG(object)

        NODE_REG(ol)

        NODE_REG(optgroup)

        NODE_REG(option)

        NODE_REG(output)

        NODE_REG(p)

        NODE_REG(param)

        NODE_REG(pre)

        NODE_REG(progress)

        NODE_REG(q)

        NODE_REG(rp)

        NODE_REG(rt)

        NODE_REG(ruby)

        NODE_REG(s)

        NODE_REG(samp)

        NODE_REG(script)

        NODE_REG(section)

        NODE_REG(select)

        NODE_REG(small)

        NODE_REG(source)

        NODE_REG(span)

        NODE_REG(strike)

        NODE_REG(strong)

        NODE_REG(style)

        NODE_REG(sub)

        NODE_REG(summary)

        NODE_REG(sup)

        NODE_REG(table)

        NODE_REG(tbody)

        NODE_REG(td)

        NODE_REG(textarea)

        NODE_REG(tfoot)

        NODE_REG(th)

        NODE_REG(thead)

        NODE_REG(time)

        NODE_REG(title)

        NODE_REG(tr)

        NODE_REG(track)

        NODE_REG(tt)

        NODE_REG(u)

        NODE_REG(ul)

        NODE_REG(var)

        NODE_REG(video)

        NODE_REG(wbr)

        NODE_REG(xmp)
    }

    inline namespace attrs
    {
        ATTR_REG(abbr)

        ATTR_REG(accept)

        ATTR_REG(accept_charset)

        ATTR_REG(accesskey)

        ATTR_REG(action)

        ATTR_REG(align)

        ATTR_REG(alink)

        ATTR_REG(alt)

        ATTR_REG(archive)

        ATTR_REG(async)

        ATTR_REG(autocomplete)

        ATTR_REG(autofocus)

        ATTR_REG(autoplay)

        ATTR_REG(axis)

        ATTR_REG(background)

        ATTR_REG(bgcolor)

        ATTR_REG(border)

        ATTR_REG(cellpadding)

        ATTR_REG(cellspacing)

        ATTR_REG(challenge)

        ATTR_REG(char)

        ATTR_REG(charoff)

        ATTR_REG(charset)

        ATTR_REG(checked)

        ATTR_REG(cite)

        ATTR_REG(class)

        ATTR_REG(classid)

        ATTR_REG(code)

        ATTR_REG(codebase)

        ATTR_REG(codetype)

        ATTR_REG(color)

        ATTR_REG(cols)

        ATTR_REG(colspan)

        ATTR_REG(compact)

        ATTR_REG(content)

        ATTR_REG(contenteditable)

        ATTR_REG(contextmenu)

        ATTR_REG(controls)

        ATTR_REG(coords)

        ATTR_REG(data)

        ATTR_REG(datetime)

        ATTR_REG(declare)

        ATTR_REG(default)

        ATTR_REG(defer)

        ATTR_REG(dir)

        ATTR_REG(disabled)

        ATTR_REG(download)

        ATTR_REG(draggable)

        ATTR_REG(dropzone)

        ATTR_REG(enctype)

        ATTR_REG(face)

        ATTR_REG(for)

        ATTR_REG(form)

        ATTR_REG(formaction)

        ATTR_REG(formenctype)

        ATTR_REG(formmethod)

        ATTR_REG(formnovalidate)

        ATTR_REG(formtarget)

        ATTR_REG(frame)

        ATTR_REG(frameborder)

        ATTR_REG(headers)

        ATTR_REG(height)

        ATTR_REG(hidden)

        ATTR_REG(high)

        ATTR_REG(href)

        ATTR_REG(hreflang)

        ATTR_REG(hspace)

        ATTR_REG(http_equiv)

        ATTR_REG(icon)

        ATTR_REG(id)

        ATTR_REG(ismap)

        ATTR_REG(keytype)

        ATTR_REG(kind)

        ATTR_REG(label)

        ATTR_REG(lang)

        ATTR_REG(language)

        ATTR_REG(link)

        ATTR_REG(list)

        ATTR_REG(longdesc)

        ATTR_REG(loop)

        ATTR_REG(low)

        ATTR_REG(manifest)

        ATTR_REG(marginheight)

        ATTR_REG(marginwidth)

        ATTR_REG(max)

        ATTR_REG(maxlength)

        ATTR_REG(media)

        ATTR_REG(method)

        ATTR_REG(min)

        ATTR_REG(multiple)

        ATTR_REG(muted)

        ATTR_REG(name)

        ATTR_REG(nohref)

        ATTR_REG(noresize)

        ATTR_REG(noshade)

        ATTR_REG(novalidate)

        ATTR_REG(nowrap)

        ATTR_REG(object)

        ATTR_REG(onabort)

        ATTR_REG(onafterprint)

        ATTR_REG(onbeforeprint)

        ATTR_REG(onbeforeunload)

        ATTR_REG(onblur)

        ATTR_REG(oncanplay)

        ATTR_REG(oncanplaythrough)

        ATTR_REG(onchange)

        ATTR_REG(onclick)

        ATTR_REG(oncontextmenu)

        ATTR_REG(ondblclick)

        ATTR_REG(ondrag)

        ATTR_REG(ondragend)

        ATTR_REG(ondragenter)

        ATTR_REG(ondragleave)

        ATTR_REG(ondragover)

        ATTR_REG(ondragstart)

        ATTR_REG(ondrop)

        ATTR_REG(ondurationchange)

        ATTR_REG(onemptied)

        ATTR_REG(onended)

        ATTR_REG(onerror)

        ATTR_REG(onfocus)

        ATTR_REG(onformchange)

        ATTR_REG(onforminput)

        ATTR_REG(onhaschange)

        ATTR_REG(oninput)

        ATTR_REG(oninvalid)

        ATTR_REG(onkeydown)

        ATTR_REG(onkeypress)

        ATTR_REG(onkeyup)

        ATTR_REG(onload)

        ATTR_REG(onloadeddata)

        ATTR_REG(onloadedmetadata)

        ATTR_REG(onloadstart)

        ATTR_REG(onmessage)

        ATTR_REG(onmousedown)

        ATTR_REG(onmousemove)

        ATTR_REG(onmouseout)

        ATTR_REG(onmouseover)

        ATTR_REG(onmouseup)

        ATTR_REG(onmousewheel)

        ATTR_REG(onoffline)

        ATTR_REG(ononline)

        ATTR_REG(onpagehide)

        ATTR_REG(onpageshow)

        ATTR_REG(onpause)

        ATTR_REG(onplay)

        ATTR_REG(onplaying)

        ATTR_REG(onpopstate)

        ATTR_REG(onprogress)

        ATTR_REG(onratechange)

        ATTR_REG(onreadystatechange)

        ATTR_REG(onredo)

        ATTR_REG(onreset)

        ATTR_REG(onresize)

        ATTR_REG(onscroll)

        ATTR_REG(onseeked)

        ATTR_REG(onseeking)

        ATTR_REG(onselect)

        ATTR_REG(onstalled)

        ATTR_REG(onstorage)

        ATTR_REG(onsubmit)

        ATTR_REG(onsuspend)

        ATTR_REG(ontimeupdate)

        ATTR_REG(onundo)

        ATTR_REG(onunload)

        ATTR_REG(onvolumechange)

        ATTR_REG(onwaiting)

        ATTR_REG(open)

        ATTR_REG(optimum)

        ATTR_REG(pattern)

        ATTR_REG(placeholder)

        ATTR_REG(poster)

        ATTR_REG(preload)

        ATTR_REG(profile)

        ATTR_REG(pubdate)

        ATTR_REG(radiogroup)

        ATTR_REG(readonly)

        ATTR_REG(rel)

        ATTR_REG(required)

        ATTR_REG(rev)

        ATTR_REG(reversed)

        ATTR_REG(rows)

        ATTR_REG(rowspan)

        ATTR_REG(rules)

        ATTR_REG(sandbox)

        ATTR_REG(scheme)

        ATTR_REG(scope)

        ATTR_REG(scrolling)

        ATTR_REG(seamless)

        ATTR_REG(selected)

        ATTR_REG(shape)

        ATTR_REG(size)

        ATTR_REG(span)

        ATTR_REG(spellcheck)

        ATTR_REG(src)

        ATTR_REG(srcdoc)

        ATTR_REG(srclang)

        ATTR_REG(standby)

        ATTR_REG(start)

        ATTR_REG(step)

        ATTR_REG(style)

        ATTR_REG(summary)

        ATTR_REG(tabindex)

        ATTR_REG(target)

        ATTR_REG(text)

        ATTR_REG(title)

        ATTR_REG(translate)

        ATTR_REG(type)

        ATTR_REG(usemap)

        ATTR_REG(valign)

        ATTR_REG(value)

        ATTR_REG(valuetype)

        ATTR_REG(vlink)

        ATTR_REG(vspace)

        ATTR_REG(width)

        ATTR_REG(wrap)

        ATTR_REG(xmlns)

    }

}


#endif//__CPP_HTML_HPP_