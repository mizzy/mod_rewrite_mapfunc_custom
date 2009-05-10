Name: mod_rewrite_mapfunc_custom
Version: 0.01
Release: 1
License: Apache Public License
Group: System Environment/Daemons
Source: %{name}-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot
BuildRequires: apr-devel, httpd-devel
Requires: httpd
Summary: Extend Apache's mod_rewrite by internal mapping functions.

%description

%prep

%setup -n %{name}

%build
%configure 
make

%install
[ -n "%{buildroot}" -a "%{buildroot}" != / ] && rm -rf %{buildroot}
make DESTDIR=$RPM_BUILD_ROOT install

%clean
[ -n "%{buildroot}" -a "%{buildroot}" != / ] && rm -rf %{buildroot}

%files
%defattr(-,root,root)
%{_libdir}/httpd/modules

%changelog

