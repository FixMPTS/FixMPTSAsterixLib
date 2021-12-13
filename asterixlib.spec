Name: lib-asterix
Version: 0.1.0
Release: 1%{?dist}
Summary: A library to decode and encode messages in Eurocontrol's Asterix format

License: LGPLv3+
URL: http://www.fixmpts.org/asterixlib
Source0: %{name}-%{version}.tar.gz

BuildRequires: ant
BuildRequires: gcc

%description
Library allowing the encoding and decoding of Asterix messages. 

For more details on the Asterix protocol pleae visit https://www.eurocontrol.int/asterix-specifications-library

%global debug_package %{nil}

%prep
rm -rf $RPM_BUILD_ROOT
%setup -q

%build
#ant all

%check

%install
install -p -m 755 -D -t $RPM_BUILD_ROOT/%{_libdir}/. lib/*

%files
#%doc README TODO COPYING ChangeLog
%{_libdir}/*

%changelog
* Mon Apr 05 2021 Felix Kreuter <felix@fixmpts.org> - 0.1.0-1
- Initial RPM release


