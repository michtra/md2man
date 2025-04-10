document.addEventListener('DOMContentLoaded', function() {
    // highlight the active page in navigation
    const currentPath = window.location.pathname;
    const currentPage = currentPath.split('/').pop();
    const navLinks = document.querySelectorAll('.nav-link');
    
    navLinks.forEach(link => {
        if (link.getAttribute('href') === currentPage) {
            link.classList.add('active');
        }
    });
    
    // generate table of contents if available
    const headings = document.querySelectorAll('.content h2, .content h3, .content h4');
    const tocContainer = document.getElementById('toc');
    
    if (tocContainer && headings.length > 0) {
        const tocTitle = document.createElement('h2');
        tocTitle.textContent = 'Table of Contents';
        tocContainer.appendChild(tocTitle);
        
        const tocList = document.createElement('ul');
        tocList.classList.add('toc-list');
        
        headings.forEach(heading => {
            const listItem = document.createElement('li');
            listItem.classList.add('toc-item', `toc-${heading.tagName.toLowerCase()}`);
            
            const link = document.createElement('a');
            link.textContent = heading.textContent;
            link.href = `#${heading.id}`;
            
            listItem.appendChild(link);
            tocList.appendChild(listItem);
        });
        
        tocContainer.appendChild(tocList);
    }
});
